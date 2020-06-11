module str

    export is_unique1, is_unique2

    #=
        Is Unique.

        Implement an algorithm to determine if a string has
        all unique characters. What if you cannot use additional
        data structures?
    =#

    function is_unique1(str)

        if str == Nothing
            return false
        end

        chars = Set(str)

        return length(chars) == length(str)
    end

    # Instead of a data structure we just use
    # a bit flag to track the characters we've
    # seen thusfar.
    function is_unique2(str)

        if str == Nothing
            return false
        end

        seen, offset = Int(0), Int('a')

        for index in firstindex(str):lastindex(str)
            char = str[index]

            if isspace(char)
                continue
            end

            position = Int(char) - offset
            mask = 1 << position

            if seen & mask == mask
                return false
            end

            seen |= mask
        end

        return true
    end

end # end module
