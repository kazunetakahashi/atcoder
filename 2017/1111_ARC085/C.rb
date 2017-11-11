n, m = gets.chomp.split(" ").map{|i| i.to_i}
puts (2 ** m) * ( (n-m) * 100 + m * 1900)
