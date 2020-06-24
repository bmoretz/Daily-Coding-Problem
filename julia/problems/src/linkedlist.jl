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

end # end module
