module linkedlist

    using DataStructures

    #=
    a few utility method for unit testing ease
    =#

    export are_equal

    function are_equal(l₁::LinkedList{T}, l₂::LinkedList{T})::Bool where T
        length(l₁) != length(l₂) && return false

        return collect(l₁) == collect(l₂)
    end

    export to_mutable_list

    function to_mutable_list(values::Vector{T}) where T
        list = MutableLinkedList()

        for value in values
            append!(list, value)
        end

        return list
    end

    #=
        Remove Dups.

        Write code to remove duplicates from an unsorted linked list.
    =#

    export dedupe

    #=
        dedupe 1

        if we get an immutable linked list, then
        we're forced to create a new one with the
        distinct elements from the passed in list.

        O(N) run-time
        O(N) memory
    =#
    function dedupe(list::LinkedList{T}) where T
        length(list) == 0 && return list

        seen = Set{T}()
        result = MutableLinkedList()

        for value in list

            value ∈ seen && continue

            append!(result, value)
            seen = union(seen, value)
        end

        return result
    end

    #=
        dedupe 2

        if we're passed a mutable linked list then
        we iterate over all the elements and mark the
        index of the duplicates in the first pass. Then
        we can iterate the indices of the duplicates and
        remove them seperately.

        O(N + D) run-time where D is the number of duplicates,
        O(1) memory
    =#
    function dedupe(list::MutableLinkedList{T}) where T

        length(list) == 0 && return list

        seen = Set{T}()
        to_delete = Vector{Integer}()

        for (index, value) in enumerate(list)
            value ∈ seen && append!(to_delete, index)
            seen = union(seen, value)
        end

        for (index, value) in enumerate(to_delete)
            position = value - (index - 1)
            delete!(list, position)
        end

        return list
    end

    #=
        Kth to Last.

        Implement an algorithm to find the kth to last
        element of a singly linked list.
    =#

    export kth_last

    #=
    kth last

    simple approach that uses two forward iterators, one
    as the main iterator and one as a runner that only starts
    iterating if the main iterator index is greater than k. Once
    the main iterator reaches the end of the list, the runner will
    be pointed to the kth last element, we just need to peel off
    the value.
    =#

    # O(N) where N = length of the list, O(1)/constant space.
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

    #=
        Delete Middle.

        Implement an algorithm to delete a node in the middle (i.e.,
        any node the first and last node, not necessarily the exact
        middle) of a singly linked list.

        EXAMPLE

        Input: the node c from the linked list
            a → b → c → d → e → f
        Result:
            a → b → d → e → f
    =#

    export delete_middle

    # O(n) where N → length of list
    function delete_middle(lst::LinkedList, k::Integer)
        T = typeof(lst).parameters[1]
        let iter = iterate(lst)
            index, new = 1, nil(T)
            while iter != nothing
                (head, tail) = iter
                index += 1
                if index <= k
                    new = cat(new, list(head))
                    iter = iterate(lst, tail)
                else
                    new = cat(new, tail)
                    break
                end
            end
            return new
        end
    end

    #=
        Partition.

        Write code to partition a linked list around a value x,
        such that all nodes less than x come before all nodes
        greater than or equal to x. If x is contained within the list,
        the values of x can appear anywhere in the "right partition";
        it does not need to appear between the left and right partitions.

        EXAMPLE

        Input: 3 → 5 → 8 → 5 → 10 → 2 → 1 [partition = 5]
        Output: 3 → 1 → 2 → 10 → 5 → 5 → 8
    =#

    export partition

    # O(n) where N → length of the list
    function partition(lst::LinkedList, value::Integer)::LinkedList
        let iter = iterate(lst)
            head, tail = nil(), nil()
            while iter != nothing
                v, s = iter

                if v < value
                    head = cons(v, head)
                else
                    tail = cons(v, tail)
                end

                iter = iterate(lst, s)
            end
            return cat(head, tail)
        end
    end

end # end module
