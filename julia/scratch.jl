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

function count_spaces(arr::Array{Char, 1})::Integer
    counter = 0
    for char in arr
        isspace(char) && (counter += 1)
    end
    return counter
end

str = "Single Space  "
t_len = length(str) - Int(2*count_spaces(collect(str))/3)

url = urlify1(str, t_len)
