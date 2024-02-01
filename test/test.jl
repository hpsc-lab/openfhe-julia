using MyOpenFHE
using Test

@testset "MyOpenFHE" begin
    @show parameters = MyOpenFHE.CCParams{MyOpenFHE.CryptoContextCKKSRNS}()
    @show cc = MyOpenFHE.GenCryptoContext(parameters)
    @show ep = MyOpenFHE.GetEncodingParams(cc[])
    @show batch_size = Int(MyOpenFHE.GetBatchSize(ep[]))

    @test batch_size == 8192
end
