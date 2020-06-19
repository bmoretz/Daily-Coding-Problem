#=
    Rotate Matrix.

    Given an image represented by and NxN matrix, where
    each pixel in the image is 4 bytes, write a method
    to rotate the image by 90 degrees.

    Can you do it in place?

=#

using LinearAlgebra
using Printf

using problems.matrix

function get_inc_mat(T, n::Integer)
    mat = Matrix{T}(undef, n, n)

    for row in 1:n
        for col in 1:n
            mat[row, col] = (row - 1)*n + col
        end
    end

    return mat
end

n = 2
matrix = get_inc_mat(Int8, n)
width, height = size(matrix)

mat = Int8[1 2;
           3 4]

rotate_matrix2(mat)
