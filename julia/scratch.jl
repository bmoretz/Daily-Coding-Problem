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

using DataStructures

l = list(4, 6, 3, 1, 3, 2, 6, 1)

k = 3

function delete_middle(lst::LinkedList, k::Integer)
    T = typeof(lst).parameters[1]
    let iter = iterate(l)
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

node = delete_middle(l, 3)
