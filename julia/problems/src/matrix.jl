module matrix

    using LinearAlgebra

    export rotate_matrix1

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


end # end module
