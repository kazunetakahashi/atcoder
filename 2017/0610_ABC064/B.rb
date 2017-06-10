n = gets.to_i
a = gets.chomp.split(" ").map{|i| i.to_i}
a.sort!
puts a.last - a.first
