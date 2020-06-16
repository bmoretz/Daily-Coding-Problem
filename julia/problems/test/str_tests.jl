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

@testset "urlify 1" begin
    @test urlify1("", 0) == ""
    @test urlify1("NoSpace", 7) == "NoSpace"
    @test urlify1("Mr John Smith    ", 13) == "Mr%20John%20Smith"
    @test urlify1("Single Space  ", 12)  == "Single%20Space"
    @test urlify1("tr i pple Space      ", 15) == "tr%20i%20pple%20Space"
end

@testset "is palindrome permutation 1" begin
    @test is_pal_perm1("") == false
    @test is_pal_perm1("atco cta") == true
    @test is_pal_perm1("A nut for a jar of tuna") == true
    @test is_pal_perm1("Amore, Roma.") == true
    @test is_pal_perm1("Ed, I saw Harpo Marx ram Oprah W. aside.") == true
end

@testset "one away 1" begin
    @test one_away1("", "") == false
    @test one_away1("pale", "ple") == true
    @test one_away1("pales", "pale") == true
    @test one_away1("pale", "balep") == true
    @test one_away1("pale", "bake") == false
    @test one_away1("PALE", "baLe") == true
    @test one_away1("PALE    ", "b    aLe") == true
    @test one_away1("PALE", "PALEB") == true
end
