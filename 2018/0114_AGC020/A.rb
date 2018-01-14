n, a, b = gets.chomp.split(" ").map{|i| i.to_i}
if (b-a-1)%2 == 0
  puts "Borys"
else
  puts "Alice"
end
