#=
    Remove Dups.

    Write code to remove duplicates from an unsorted linked list.
=#

module scratch

    const Opt = Union{T, Nothing} where T

    struct List{T}
        head::T
        tail::Opt{List{T}}
    end

    head(l::List) = l.head
    tail(l::List) = l.tail

    export buildlist

    # built a list from an array
    buildlist(array::AbstractArray{T}, n) where T =
        n == lastindex(array) ?
        List{T}(array[n], nothing) :
        List(array[n], buildlist(array, n+1))

    buildlist(array) = buildlist(array, firstindex(array))

    # implement the iteration protocol
    Base.iterate(l::List) = iterate(l, l)
    Base.iterate(::List, l::List) = head(l), tail(l)
    Base.iterate(::List, ::Nothing) = nothing

    # demo:
    list = buildlist(1:5)
    @show list

    for val in list
        println(val)
    end

end

module remove_dupes

    abstract type AbstractNode{T} end

    mutable struct ListNode{T} <: AbstractNode{T}
        data::T
        next::ListNode{T}
        ListNode{T}() where T = (x=new(); x; x.next=x;)
    end
    ListNode(d::T, n) where T = ListNode{T}(d, n)

end

using .scratch

# demo:
list = buildlist(1:5)
@show list
