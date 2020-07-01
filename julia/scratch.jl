using DataStructures

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

function partition(lst::LinkedList, value::Integer)::LinkedList
    let iter = iterate(lst)
        head, tail = nil(), nil()
        while iter != nothing
            v, s = iter

            if v < partition
                head = cons(v, head)
            else
                tail = cons(v, tail)
            end

            iter = iterate(lst, s)
        end
        new = cat(head, tail)
    end
    return new
end


partition(lst, value)


lst = list(3, 5, 8, 5, 10, 2, 1)
value = 5
