using Test
using DataStructures

using problems.linkedlist

@testset "dedupe 1 (immutable)" begin

    @test dedupe(list()) == list()

    @testset "case 1" begin
        actual = collect(dedupe(list(4, 6, 3, 1, 3, 2, 6, 1)))
        expected = [4, 6, 3, 1, 2]

        @test actual == expected
    end

    @testset "case 2" begin
        actual = collect(dedupe(list(4, 6, 3, 1, 3, 2, 6, 1, 7, 1, 2)))
        expected = [4, 6, 3, 1, 2, 7]

        @test actual == expected
    end

    @testset "case 3" begin
        actual = collect(dedupe(list(4, 6, 3, 1, 3, 2, 6, 1, 7, 1, 2)))
        expected = [4, 6, 3, 1, 2, 7]

        @test actual == expected
    end

    @testset "case 4" begin
        actual = collect(dedupe(list(1, 1, 1, 2, 3, 1, 1, 2, 3, 1, 4, 4)))
        expected = [1, 2, 3, 4]

        @test actual == expected
    end

    @testset "case 5" begin
        actual = collect(dedupe(list(1, 1, 'a', 2, 3, 1, 1, 2, 3, 'b', 4, 4)))
        expected = [1, 'a', 2, 3, 'b', 4]

        @test actual == expected
    end

end

@testset "dedupe 2 (mutable)" begin

    @test dedupe(MutableLinkedList()) == MutableLinkedList()

    @testset "case 1" begin

        lst = to_mutable_list([4, 6, 3, 1, 3, 2, 6, 1])

        actual = collect(dedupe(lst))
        expected = [4, 6, 3, 1, 2]

        @test actual == expected
    end

    @testset "case 2" begin

        lst = to_mutable_list([4, 6, 3, 1, 3, 2, 6, 1, 7, 1, 2])

        actual = collect(dedupe(lst))
        expected = [4, 6, 3, 1, 2, 7]

        @test actual == expected
    end

    @testset "case 3" begin

        lst = to_mutable_list([4, 6, 3, 1, 3, 2, 6, 1, 7, 1, 2])

        actual = collect(dedupe(lst))
        expected = [4, 6, 3, 1, 2, 7]

        @test actual == expected
    end

    @testset "case 4" begin
        lst = to_mutable_list([1, 1, 1, 2, 3, 1, 1, 2, 3, 1, 4, 4])

        actual = collect(dedupe(lst))
        expected = [1, 2, 3, 4]

        @test actual == expected
    end

    @testset "case 5" begin
        lst = to_mutable_list([1, 1, 'a', 2, 3, 1, 1, 2, 3, 'b', 4, 4])

        actual = collect(dedupe(lst))
        expected = [1, 'a', 2, 3, 'b', 4]

        @test actual == expected
    end

end
