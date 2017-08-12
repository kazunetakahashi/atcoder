n = gets.to_s
# a = gets.chomp.split(" ").map{|i| i.to_i}
p n.reverse
if n.reverse == n
  puts "Yes"
else
  puts "No"
end
