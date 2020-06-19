#=
    Rotate Matrix.

    Given an image represented by and NxN matrix, where
    each pixel in the image is 4 bytes, write a method
    to rotate the image by 90 degrees.

    Can you do it in place?

=#

using LinearAlgebra

function rotate_matrix1(mat::Array)

    length(mat) <= 1 && return mat

    width, height = size(mat)
    result = Matrix(undef, width, height)

    for row in 1:height
        for col in 1:width
            result[col, height - row + 1] = mat[row, col]
        end
    end

    return result
end

n = 5
mat = Matrix{Int8}(undef, n, n)

function get_inc_mat(T, n::Integer)
    mat = Matrix{T}(undef, n, n)

    for row in 1:n
        for col in 1:n
            mat[row, col] = (row - 1)*n + col
        end
    end

    return mat
end

mat = get_inc_mat(Int8, 3)
width, height = size(mat)

print(mat)
println("")
print(rotate_matrix1(mat))

for row in 1:height
    for col in 1:width
        result[col, height - row + 1] = mat[row, col]
    end
end

mat = Int8[1 2; 3 4]
rotate_matrix1(mat)
println("")

result = rotate_matrix1(mat)
