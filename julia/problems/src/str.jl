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

    #=
        URLify.

        Write a method to replacea all spaces in a string with
        '%20'. You may assume that the string has sufficient space
        at the end to hold the additional characters, and that you
        are given the true length of the string.

        EXAMPLE:

        Input: "Mr John Smith    ", 13
        Ouput: "Mr%20%John%20Smith"
    =#

    export urlify1
    
    function urlify1(str::String, len::Integer)::String

        function count_spaces(arr::Array{Char, 1})::Integer
            counter = 0
            for char in arr
                isspace(char) && (counter += 1)
            end
            return counter
        end

        arr = collect(str)
        total_spaces = count_spaces(arr)
        actual, position = length(arr), len

        for index in len:-1:1
            if isspace(arr[position])
                arr[actual] = '0'
                arr[actual-1] = '2'
                arr[actual-2] = '%'

                actual -= 2
            else
                arr[actual] = arr[position]
            end

            actual -= 1; position -= 1
        end

        return String(arr)
    end

end # end module
