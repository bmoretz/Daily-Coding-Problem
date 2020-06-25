#=
    Kth to Last.

    Implement an algorithm to find the kth to last
    element of a singly linked list.
=#

using DataStructures


function kth_last(lst::LinkedList{T}, k::Integer) where T
    result, index = nothing, 0

    let iter = iterate(lst)
        let runner = iterate(lst)
            while iter !== nothing
                (_, main_state) = iter
                (_, run_state) = runner

                if k < index
                    runner = iterate(lst, run_state)
                end

                iter = iterate(lst, main_state)
                index += 1
            end

            result, _ = Iterators.peel(runner)
        end
    end

    return result
end

l = list(4, 6, 3, 1, 3, 2, 6, 1)
k = 0

result = kth_last(l, k)
