r, g, b = gets.chomp.split(" ").map{|i| i.to_s}
if (r+g+b).to_i % 4 == 0
  puts "YES"
else
  puts "NO"
end
