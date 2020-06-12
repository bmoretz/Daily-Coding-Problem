module str

    export is_unique1, is_unique2

    #=
        Is Unique.

        Implement an algorithm to determine if a string has
        all unique characters. What if you cannot use additional
        data structures?
    =#

    function is_unique1(str::String)::Bool
        return length(Set(str)) == length(str)
    end

    # Instead of a data structure we just use
    # a bit flag to track the characters we've
    # seen thusfar.
    function is_unique2(str::String)::Bool

        seen, offset = Int(0), Int('a')

        for index in firstindex(str):lastindex(str)
            char = str[index]

            isspace(char) && continue

            mask = 1 << (Int(char) - offset)
            seen & mask == mask && return false

            seen |= mask
        end

        return true
    end

    #=
        Check Permutation.

        Given two strings, write a function to decide if one is
        a permutation of the other.
    =#

    export is_permutation1, is_permutation2

    # O(S₁log(S₁) + S₂log(S₂))
    function is_permutation1(s₁::String, s₂::String)

        char_sort(s) = string(sort(collect(s)))

        length(s₁) != length(s₂) && return false

        return char_sort(s₁) == char_sort(s₂)
    end

    # O(S₁ + S₂)
    function is_permutation2(s₁::String, s₂::String)::Bool

        function to_dict(str::String)::Dict
            dict = Dict{Char, Integer}()

            for char in str
                if char ∉ keys(dict)
                    dict[char] = 0
                else
                    dict[char] += 1
                end
            end

            return dict
        end

        n₁ = length(s₁); n₂ = length(s₂)

        n₁ != n₂ && return false

        d₁, d₂ = (if (n₁ < n₂)
                    to_dict(s₁), to_dict(s₂)
                 else
                     to_dict(s₂), to_dict(s₁)
                end)

        keys(d₁) != keys(d₂) && return false

        for k in keys(d₁)
            d₁[k] != d₂[k] && return false
        end

        return true
    end

end # end module
