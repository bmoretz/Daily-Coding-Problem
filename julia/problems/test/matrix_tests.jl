using Test
using LinearAlgebra

using problems.matrix

@testset "matrix rotation 1" begin

    @testset "1x1" begin
        mat = Int8[1;]
        actual = rotate_matrix1(mat)
        expected = Int8[1;]

        @test actual == expected
    end

    @testset "2x2" begin
        mat = Int8[1 2;
                   3 4]

        actual = rotate_matrix1(mat)

        expected = Int8[3 1;
                        4 2]

        @test actual == expected
    end

    @testset "3x3" begin
        mat = Int8[1 2 3;
                   4 5 6;
                   7 8 9]

        actual = rotate_matrix1(mat)

        expected = Int8[7 4 1;
                        8 5 2;
                        9 6 3]

        @test actual == expected
    end

    @testset "4x4" begin

        mat = Int8[1 2 3 4;
                   5 6 7 8;
                   9 10 11 12;
                   13 14 15 16]

        actual = rotate_matrix1(mat)

        expected = Int8[13 9 5 1;
                        14 10 6 2;
                        15 11 7 3;
                        16 12 8 4]

        @test actual == expected
    end

    @testset "5x5" begin

        mat = Int8[1 2 3 4 5;
                   6 7 8 9 10;
                   11 12 13 14 15;
                   16 17 18 19 20;
                   21 22 23 24 25]

        actual = rotate_matrix1(mat)

        expected = Int8[21 16 11 6 1;
                        22 17 12 7 2;
                        23 18 13 8 3;
                        24 19 14 9 4;
                        25 20 15 10 5]

        @test actual == expected
    end
end

@testset "matrix rotation 2" begin

    @testset "1x1" begin
        mat = Int8[1;]
        actual = rotate_matrix2(mat)
        expected = Int8[1;]

        @test actual == expected
    end

    @testset "2x2" begin
        mat = Int8[1 2;
                   3 4]

        actual = rotate_matrix2(mat)

        expected = Int8[3 1;
                        4 2]

        @test actual == expected
    end

    @testset "3x3" begin
        mat = Int8[1 2 3;
                   4 5 6;
                   7 8 9]

        actual = rotate_matrix2(mat)

        expected = Int8[7 4 1;
                        8 5 2;
                        9 6 3]

        @test actual == expected
    end

    @testset "4x4" begin

        mat = Int8[1 2 3 4;
                   5 6 7 8;
                   9 10 11 12;
                   13 14 15 16]

        actual = rotate_matrix2(mat)

        expected = Int8[13 9 5 1;
                        14 10 6 2;
                        15 11 7 3;
                        16 12 8 4]

        @test actual == expected
    end

    @testset "5x5" begin

        mat = Int8[1 2 3 4 5;
                   6 7 8 9 10;
                   11 12 13 14 15;
                   16 17 18 19 20;
                   21 22 23 24 25]

        actual = rotate_matrix2(mat)

        expected = Int8[21 16 11 6 1;
                        22 17 12 7 2;
                        23 18 13 8 3;
                        24 19 14 9 4;
                        25 20 15 10 5]

        @test actual == expected
    end

    @testset "zero matrix 1" begin

        @testset "2x2" begin
            mat = Int8[1 2;
                       0 4]

            actual = zero_matrix1(mat)

            expected = Int8[0 2;
                            0 0]

            @test actual == expected
        end

    end

    @testset "3x3" begin
        mat = Int8[1 2 3;
                   4 0 6;
                   7 8 9]

        actual = zero_matrix1(mat)

        expected = Int8[1 0 3;
                        0 0 0;
                        7 0 9]

        @test actual == expected
    end

    @testset "4x4" begin

        mat = Int8[0 2 3 4;
                   5 6 7 8;
                   9 10 0 0;
                   13 14 15 16]

        actual = zero_matrix1(mat)

        expected = Int8[0 0 0 0;
                        0 6 0 0;
                        0 0 0 0;
                        0 14 0 0]

        @test actual == expected
    end

    @testset "5x5" begin

        mat = Int8[1 2 3 4 5;
                   6 7 8 9 10;
                   0 12 0 14 15;
                   16 17 18 19 20;
                   0 22 0 24 25]

        actual = zero_matrix1(mat)

        expected = Int8[0 2 0 4 5;
                        0 7 0 9 10;
                        0 0 0 0 0;
                        0 17 0 19 20;
                        0 0 0 0 0]

        @test actual == expected
    end

end
