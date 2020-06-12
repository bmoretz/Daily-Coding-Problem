#=
    Check Permutation.

    Given two strings, write a function to decide if one is
    a permutation of the other.
=#

function is_permutation1(s₁::String, s₂::String)::Bool

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

    (length(s₁) == 0 || length(s₂) == 0) && return false

    d₁ = to_dict(s₁); d₂ = to_dict(s₂)

    keys(d₁) != keys(d₂) && return false

    for k in keys(d₁)
        d₁[k] != d₂[k] && return false
    end

    return true
end

str1, str2 = "abcdef", "fedcba"

res = is_permutation1(str1, str2)

print(res)
