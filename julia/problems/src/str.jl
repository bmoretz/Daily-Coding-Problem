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

        function to_dict(str::String)::Dict{Char, Integer}
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

    # O(N), where N = len(S)
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

    #=
        Palindrome Permutation.

        Given a string, write a function to check if it is
        a permutation of a palindrome. A palindrome is a word
        or phrase that is the same forwards and backwards. A
        permutation is a rearrangement of letters. The palindrome
        does not need to be limited to just dictionary words.

        EXAMPLE:

        Input: Tact Coa
        Output: True (permutations: "taco cat", "atco cta", etc.)
    =#

    export is_pal_perm1

    # O(N), where N = len(S)
    function is_pal_perm1(str::String)::Bool

        function char_counts(str::String)::Array{Integer}
            counts = Dict{Char, Integer}()

            for c in lowercase(str)

                !isletter(c) && continue

                if c ∉ keys(counts)
                    counts[c] = 1
                else
                    counts[c] += 1
                end
            end

            return collect(values(counts))
        end

        isempty(str) && return false

        return count(x -> isodd(x), char_counts(str)) <= 1
    end

    #=
        One Away.

        There are three types of edits that can be performed on
        strings: insert a character, remove a character, or
        replace a character. Given two strings, write a function
        to check if they are one edit (or zero edits) away.

        EXAMPLE:

        pale, ple -> true
        pales, pale -> true
        pale, bale -> true
        pale, bake -> false
    =#

    export one_away1

    function one_away1(s₁::String, s₂)::Bool
        function to_dict(str::String)::Dict{Char, Integer}
            dict = Dict{Char, Integer}()

            for c in lowercase(str)

                !isletter(c) && continue

                if c ∉ keys(dict)
                    dict[c] = 1
                else
                    dict[c] += 1
                end
            end

            return dict
        end

        (isempty(s₁) || isempty(s₂)) && return false

        d₁, d₂ = (if (length(s₁) > length(s₂))
                    to_dict(s₁), to_dict(s₂)
                else
                    to_dict(s₂), to_dict(s₁)
                end)

        δ = 0

        for k in keys(d₁)
            (k ∈ keys(d₂) && d₁[k] == d₂[k]) && continue
            δ += d₁[k]

            δ > 1 && return false
        end

        return true
    end

    #=
        String Compression.

        Implement  a method to perform basic string compression using
        the counts of repeated characters. For example, the string
        "aabcccccaaa" would become a2b1c5a3. If the "compressed" string
        would not become smaller than the original string, your method
        should return the original string. You can assume the string
        has only uppercase and lowercase letters (a-z.)

    =#

    using Printf

    export compress1

    function compress1(str::String)::String
        n = length(str)
        n == 0 && return str

        prev, counter = str[1], 1
        compressed = string()

        for index in 2:n
            current = str[index]

            if prev == current
                counter += 1
            else
                compressed = @sprintf "%s%s%i" compressed prev counter
                counter = 1
            end
            prev = current
        end

        compressed = @sprintf "%s%s%i" compressed prev counter

        l₁, l₂ = length(str), length(compressed)

        return if l₁ <= l₂ str else compressed end
    end

    #=
        String Rotation.

        Assume you have a method isSubstring which checks if one
        word is a substring of another. Given two strings,
        s₁ and s₂, write code to check if s₂ is a rotation
        of s₁ using only one call to isSubstring (e.g,
        "waterbottle" is a rotation of "erbottlewat").
    =#

    # internal package function for is_rotation
    function is_substring(s₁::String, s₂::String)::Bool
        return occursin(s₁, s₂)
    end

    export is_rotation1
    
    #=
    Brute Force to meet requirments of the "is substring" single
    call constraint.

    O(N) where N = length of s₁
    =#
    function is_rotation1(s₁::String, s₂::String)::Bool

        function get_rotations(str::String, delim::Char='|')::String
            rotations = str * delim

            for index in firstindex(str):lastindex(str)

                prefix = str[index + 1:end]
                suffix = str[1:index]

                rotations *= prefix * suffix * delim
            end

            return rotations
        end

        (length(s₁) == 0 || length(s₂) == 0) && return false

        rotations = get_rotations(s₁)

        return is_substring(s₂, rotations)
    end

end # end module
