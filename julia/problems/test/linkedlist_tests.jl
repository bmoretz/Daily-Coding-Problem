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

@testset "k-th last" begin

    @testset "case 1" begin

        lst = list(4, 6, 3, 1, 3, 2, 6, 1)

        actual = kth_last(lst, 0)
        expected = 1

        @test actual == expected
    end

    @testset "case 2" begin

        lst = list(4, 6, 3, 1, 3, 2, 6, 1)

        actual = kth_last(lst, 1)
        expected = 6

        @test actual == expected
    end

    @testset "case 3" begin

        lst = list(4, 6, 3, 1, 3, 2, 6, 1)

        actual = kth_last(lst, 2)
        expected = 2

        @test actual == expected
    end

    @testset "case 4" begin

        lst = list(4, 6, 3, 1, 3, 2, 6, 1)

        actual = kth_last(lst, 7)
        expected = 4

        @test actual == expected
    end

    @testset "case 5" begin

        lst = list(4, 6, 3, 1, 3, 2, 6, 1)

        actual = kth_last(lst, 6)
        expected = 6

        @test actual == expected
    end
end


@testset "delete middle" begin

    @testset "case 1" begin

        lst = list(4, 6, 3, 1, 3, 2, 6, 1)

        actual = delete_middle(lst, 4)
        expected = list(4, 6, 3, 3, 2, 6, 1)

        @test actual == expected
    end

    @testset "case 2" begin

        lst = list(4, 6, 2, 3, 1, 3, 2, 6, 1)

        actual = delete_middle(lst, 3)
        expected = list(4, 6, 3, 1, 3, 2, 6, 1)

        @test actual == expected
    end

    @testset "case 3" begin

        lst = list(4, 6, 2, 3, 1, 3, 2, 6, 1, 7)

        actual = delete_middle(lst, 6)
        expected = list(4, 6, 2, 3, 1, 2, 6, 1, 7)

        @test actual == expected
    end

    @testset "case 4" begin

        lst = list(4, 6, 2, 3, 1, 3, 2, 6, 1, 7, 8)

        actual = delete_middle(lst, 2)
        expected = list(4, 2, 3, 1, 3, 2, 6, 1, 7, 8)

        @test actual == expected
    end

    @testset "case 5" begin

        lst = list(4, 6, 2, 3, 1, 3, 2, 6, 1, 7, 8, 10)

        actual = delete_middle(lst, 10)
        expected = list(4, 6, 2, 3, 1, 3, 2, 6, 1, 8, 10)

        @test actual == expected
    end
end

@testset "partition" begin

    @testset "case 1" begin

        lst = list(4, 6, 3, 1, 3, 2, 6, 1)

        actual = partition(lst, 4)
        expected = list(1, 2, 3, 1, 3, 6, 6, 4)

        @test actual == expected
    end

    @testset "case 2" begin

        lst = list(4, 6, 2, 3, 1, 3, 2, 6, 1)

        actual = partition(lst, 3)
        expected = list(1, 2, 1, 2, 6, 3, 3, 6, 4)

        @test actual == expected
    end

    @testset "case 3" begin

        lst = list(4, 6, 2, 3, 1, 3, 2, 6, 1, 7)

        actual = partition(lst, 6)
        expected = list(1, 2, 3, 1, 3, 2, 4, 7, 6, 6)

        @test actual == expected
    end

    @testset "case 4" begin

        lst = list(4, 6, 2, 3, 1, 3, 2, 6, 1, 7, 8)

        actual = partition(lst, 2)
        expected = list(1, 1, 8, 7, 6, 2, 3, 3, 2, 6, 4)

        @test actual == expected
    end

    @testset "case 5" begin

        lst = list(4, 6, 2, 3, 1, 3, 2, 6, 1, 7, 8, 10)

        actual = partition(lst, 10)
        expected = list(8, 7, 1, 6, 2, 3, 1, 3, 2, 6, 4, 10)

        @test actual == expected
    end
end
