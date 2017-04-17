n = gets.to_i
a = gets.chomp.split(" ").map{|x| x.to_i}
s = gets.chomp

x = s.count("M")
y = s.count("m")

for i in 0...a.size()-x
  ans = []
  ans << a[i..i+x+1].max
end

a = ans

for i in 0...a.size()-y
  ans = []
  ans << a[i..i+y].min
end

a = ans

puts a[0]
