module matrix

    using LinearAlgebra

    # simple function for building a
    # strickly increasing matrix,
    # which is useful for testing.
    function get_inc_mat(T, n::Integer)::Matrix
        mat = Matrix{T}(undef, n, n)

        for row in 1:n
            for col in 1:n
                mat[row, col] = (row - 1)*n + col
            end
        end

        return mat
    end

    export rotate_matrix1

    # long way, basically a brute force solution
    # with O(n²) run-time and O(N) memory.
    # Which, is bad.
    function rotate_matrix1(mat::Array)::Array

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
    function rotate_matrix2(mat::Array)::Array
        length(mat) <= 1 && return mat

        return reverse(transpose(Matrix(mat)), dims=2)
    end

    export zero_matrix1

    # O(N) solution
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

end # end module
