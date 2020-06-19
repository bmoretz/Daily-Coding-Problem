#=
    Zero Matrix.

    Write an algorithm such that if an element in an
    MxN matrix is 0, its entire row and column are set
    to zero.
=#

using LinearAlgebra
using problems.matrix

function zero_matrix1(mat::Matrix)::Array

    function zero_row(mat::Matrix, row::Integer)

        height, width = size(mat)

        for index in 1:width
            mat[row, index] = 0
        end
    end

    function zero_column(mat::Matrix, col::Integer)

        height, width = size(mat)

        for index in 1:height
            mat[index, col] = 0
        end
    end

    length(mat) <= 1 && return mat

    height, width = size(mat)

    zero_rows, zero_cols = Dict{Integer, Bool}(), Dict{Integer, Bool}()

    for row in 1:height
        for col in 1:width
            if mat[row, col] == 0
                if row ∉ keys(zero_rows)
                    zero_rows[row] = true
                end

                if col ∉ keys(zero_cols)
                    zero_cols[col] = true
                end

            end
        end
    end

    for row in keys(zero_rows)
        zero_row(mat, row)
    end

    for col in keys(zero_cols)
        print(col)
        zero_column(mat, col)
    end

    return mat
end


n = 4
mat = get_inc_mat(Int8, n)
mat[1, 1] = 0

mat = zero_matrix1(mat)

mat
