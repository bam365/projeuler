open Core.Std

(* Ugly, but fast *)
let pow10 = function
    | 0 -> 1 | 1 -> 10 | 2 -> 100 | 3 -> 1000
    | 4 -> 10000 | 5 -> 100000 | _ -> 1000000

let count_digits = function
    | n when n < 10 -> 1
    | n when n < 100 -> 2
    | n when n < 1000 -> 3
    | n when n < 10000 -> 4
    | n when n < 100000 -> 5
    | _ -> 6

let digit d n = (n mod (pow10 (d + 1))) / (pow10 d)

let palindrome n =
    let count = (count_digits n) - 1 in
    let rec loop d =
        let d' = count - d in
        if d >= d' then true
        else if (digit d n) <> (digit d' n) then false
        else loop (d + 1)
    in
    loop 0

let rec largest_palindrome max i j =
    if i > 999 then max
    else
        let prod = i * j in
        let i', j' = if j = 999 then ((i+1), 100) else (i, (j+1)) in
        let max' = 
            if (palindrome prod) && (prod > max) then prod else max
        in
        largest_palindrome max' i' j'
    

let () = printf "%d\n" (largest_palindrome 0 100 100)
