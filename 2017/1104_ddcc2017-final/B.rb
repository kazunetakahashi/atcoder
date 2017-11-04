n, z = gets.chomp.split(" ").map{|i| i.to_i}
a = gets.chomp.split(" ").map{|i| i.to_i}

ans = 1

a.each{|it|
  ans = ans.lcm(it.gcm(z))
}

puts ans
