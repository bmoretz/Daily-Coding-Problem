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

function is_pal_perm1(str::String)::Bool

    function char_counts(str::String)
        counts = Dict{Char, Integer}()

        for c in lowercase(str)

            !isletter(c) && continue

            if c ∉ keys(dict)
                counts[c] = 1
            else
                counts[c] += 1
            end
        end

        return collect(values(counts))
    end

    return count(x -> isodd(x), char_counts(str)) <= 1

end

str = "Amore, Roma."

char_counts(str)
is_pal_perm1(str)
