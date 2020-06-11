using Test

using problems.str

@testset "is unique 1" begin

    @test is_unique1(Nothing) == false
    @test is_unique1("") == true
    @test is_unique1("abcdefg")  == true
    @test is_unique1("abcda") == false
    @test is_unique1("is unique") == false
end

@testset "is unique 2" begin

    @test is_unique2(Nothing) == false
    @test is_unique2("") == true
    @test is_unique2("abcdefg")  == true
    @test is_unique2("abcda") == false
    @test is_unique2("is unique") == false
end
