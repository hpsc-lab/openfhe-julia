using MyOpenFHE
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
    @show get_native_int()
end
