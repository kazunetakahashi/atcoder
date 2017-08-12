n = gets.to_i
t = Array.new(n)
for i in 0...n
  t[i] = gets.to_i
end
ans = 1
for i in 0...n
  ans = ans.lcm(t[i])
end
puts ans
