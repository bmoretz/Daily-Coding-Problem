module matrix

    using LinearAlgebra

    export rotate_matrix1

    # long way, basically a brute force solution
    # with O(n²) run-time and O(N) memory.
    # Which, is bad.
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

    export rotate_matrix2

    # Rotate 90+ = transpose, rev
    # in place
    function rotate_matrix2(mat::Array)
        length(mat) <= 1 && return mat
        
        return reverse(transpose(Matrix(mat)), dims=2)
    end

end # end module
