n = gets.chomp
# a = gets.chomp.split(" ").map{|i| i.to_i}
if n.reverse == n
  puts "Yes"
else
  puts "No"
end
