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

str = "aabcccccaaa"
compress1(str)
