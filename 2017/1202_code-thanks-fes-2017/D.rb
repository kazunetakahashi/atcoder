n, m = gets.chomp.split(" ").map{|i| i.to_i}
d = n.gcd(m)
puts m-d
