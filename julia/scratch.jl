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

function one_away(s₁::String, s₂)::Bool
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

str1, str2 = "PALE    ", "b    aLe"
one_away(str1, str2)
