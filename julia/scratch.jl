#=
    String Rotation.

    Assume you have a method isSubstring which checks if one
    word is a substring of another. Given two strings,
    s₁ and s₂, write code to check if s₂ is a rotation
    of s₁ using only one call to isSubstring (e.g,
    "waterbottle" is a rotation of "erbottlewat").
=#

function is_substring(s₁::String, s₂::String)::Bool
    return occursin(s₁, s₂)
end

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

s₁, s₂ = "waterbottle", "erbottlewat"

print(length(s₂))
result = is_rotation1(s₁, s₂)
