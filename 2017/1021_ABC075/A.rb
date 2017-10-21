a = gets.chomp.split(" ").map{|i| i.to_i}.sort
if a[0] == a[1]
  puts a[2]
else
  puts a[0]
end
