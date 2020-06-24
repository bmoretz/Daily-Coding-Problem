#=
    Remove Dups.

    Write code to remove duplicates from an unsorted linked list.
=#

using DataStructures

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

function dedupe(list::MutableLinkedList{T}) where T

    length(list) == 0 && return list

    seen = Set{T}()
    to_delete = Vector{Integer}()

    for enum in enumerate(list)
        index, value = enum
        value ∈ seen && append!(to_delete, index)
        seen = union(seen, value)
    end

    for enum in enumerate(to_delete)
        index, value = enum
        position = value - (index - 1)
        delete!(list, position)
    end

    return list
end

function to_list(values::Vector{T}) where T
    list = MutableLinkedList()

    for v in values
        append!(l, v)
    end

    return
end

dedupe(list(1, 1, 'a', 2, 3, 1, 1, 2, 3, 'b', 4, 4))

function are_equal(l₁::LinkedList{T}, l₂::LinkedList{T})::Bool where T
    length(l₁) != length(l₂) && return false

    return collect(l₁) == collect(l₂)
end

dedupe2(l)
