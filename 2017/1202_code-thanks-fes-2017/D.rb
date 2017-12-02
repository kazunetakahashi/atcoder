n, m = gets.chomp.split(" ").map{|i| i.to_i}
d = [n, m].gcd
puts m-d
