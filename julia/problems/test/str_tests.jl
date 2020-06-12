using Test

using problems.str

@testset "is unique 1" begin
    @test is_unique1("") == true
    @test is_unique2("fjdaslk") == true
    @test is_unique1("abcdefg")  == true
    @test is_unique1("abcda") == false
    @test is_unique1("is unique") == false
end

@testset "is unique 2" begin
    @test is_unique2("") == true
    @test is_unique2("fjdaslk") == true
    @test is_unique2("abcdefg")  == true
    @test is_unique2("abcda") == false
    @test is_unique2("is unique") == false
end

@testset "is permutation 1" begin
    @test is_permutation1("abcdef", "fedcba") == true
    @test is_permutation1("abcdef", "fedcbaa") == false
    @test is_permutation1("fabfcdef", "abcdefff")  == true
    @test is_permutation1("perm1", "1perm") == true
    @test is_permutation1("perm1", "perm2") == false
end

@testset "is permutation 2" begin
    @test is_permutation2("abcdef", "fedcba") == true
    @test is_permutation2("abcdef", "fedcbaa") == false
    @test is_permutation2("fabfcdef", "abcdefff")  == true
    @test is_permutation2("perm1", "1perm") == true
    @test is_permutation2("perm1", "perm2") == false
end
