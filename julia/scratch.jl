#=
    Check Permutation.

    Given two strings, write a function to decide if one is
    a permutation of the other.
=#

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

str1, str2 = "abcdef", "fedcba"

res1 = is_permutation1(str1, str2)
res2 = is_permutation2(str1, str2)

print(res)
