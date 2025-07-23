using MyOpenFHE, CxxWrap
using Test

@testset "MyOpenFHE" begin
    @show parameters = MyOpenFHE.CCParams{MyOpenFHE.CryptoContextCKKSRNS}()
    @show cc = MyOpenFHE.GenCryptoContext(parameters)
    @show ep = MyOpenFHE.GetEncodingParams(cc[])
    @show batch_size = Int(MyOpenFHE.GetBatchSize(ep[]))

    @test batch_size == 8192

    x = [0.25, 0.5, 0.75, 1.0, 2.0, 3.0, 4.0, 5.0]
    @show ptxt = MyOpenFHE.MakeCKKSPackedPlaintext(cc[], MyOpenFHE.CxxWrap.StdVector(x), 1, 0,
        MyOpenFHE.CxxWrap.StdLib.SharedPtr{MyOpenFHE.ILDCRTParams{MyOpenFHE.ubint{UInt64}}}(),
        0)
    @show MyOpenFHE.SetLength(ptxt[], length(x))
    @show ep = MyOpenFHE.GetEncodingParams(ptxt[])
    @show batch_size = Int(MyOpenFHE.GetBatchSize(ep[]))

    @test batch_size == 8192



    parameters = MyOpenFHE.CCParams{MyOpenFHE.CryptoContextCKKSRNS}()

    secret_key_distribution = MyOpenFHE.UNIFORM_TERNARY
    MyOpenFHE.SetSecretKeyDist(parameters, secret_key_distribution)

    MyOpenFHE.SetSecurityLevel(parameters, MyOpenFHE.HEStd_NotSet)
    MyOpenFHE.SetRingDim(parameters, 1 << 12)

    rescale_technique = MyOpenFHE.FLEXIBLEAUTO
    dcrt_bits = 59;
    first_modulus = 60;

    MyOpenFHE.SetScalingModSize(parameters, dcrt_bits)
    MyOpenFHE.SetScalingTechnique(parameters, rescale_technique)
    MyOpenFHE.SetFirstModSize(parameters, first_modulus)

    level_budget = [4, 4]

    levels_available_after_bootstrap = 10
    depth = levels_available_after_bootstrap + MyOpenFHE.GetBootstrapDepth(CxxWrap.StdVector(UInt32.(level_budget)), secret_key_distribution)
    MyOpenFHE.SetMultiplicativeDepth(parameters, depth)

    cc = MyOpenFHE.GenCryptoContext(parameters)

    MyOpenFHE.Enable(cc[], MyOpenFHE.PKE)
    MyOpenFHE.Enable(cc[], MyOpenFHE.KEYSWITCH)
    MyOpenFHE.Enable(cc[], MyOpenFHE.LEVELEDSHE)
    MyOpenFHE.Enable(cc[], MyOpenFHE.ADVANCEDSHE)
    MyOpenFHE.Enable(cc[], MyOpenFHE.FHE)

    key_pair = MyOpenFHE.KeyGen(cc[])
    pubkey = MyOpenFHE.public_key(key_pair)
    privkey = MyOpenFHE.private_key(key_pair)
    MyOpenFHE.EvalMultKeyGen(cc[], privkey);
    MyOpenFHE.EvalBootstrapKeyGen(cc[], privkey, num_slots);

    x = [0.25, 0.5, 0.75, 1.0, 2.0, 3.0, 4.0, 5.0]
    encoded_length = length(x)

    # We start with a depleted ciphertext that has used up all of its levels.
    ptxt = MyOpenFHE.MakeCKKSPackedPlaintext(cc[], CxxWrap.StdVector(x), 1, 1)

    MyOpenFHE.SetLength(ptxt[], encoded_length)
    println("Input: ", ptxt)

    ciphertext = MyOpenFHE.Encrypt(cc[], pubkey, ptxt)

    println("Initial number of levels remaining: ", depth - MyOpenFHE.GetLevel(ciphertext[]))

    # Perform the bootstrapping operation. The goal is to increase the number of levels
    # remaining for HE computation.
    ciphertext_after = MyOpenFHE.Compress(cc[], ciphertext, 1)

    println("Number of levels remaining after bootstrapping: ", depth - MyOpenFHE.GetLevel(ciphertext_after[]))
    println()
end
