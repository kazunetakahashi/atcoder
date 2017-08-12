a, b, c, d = gets.chomp.split(" ").map{|i| i.to_i}
x = Array.new(1000){0}
for i in a...b
  x[i] += 1
end
for i in c...d
  x[i] += 1
end
ans = 0
for i in 0...1000
  if x[i] == 2
    ans += 1
  end
end
puts ans
