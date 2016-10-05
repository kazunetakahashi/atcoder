s = gets.chomp

ary = [s]

for i in 1..s.size-1
  j = s.size()-1 - i
  tmp = []
  ary.each{|str|
    tmp << str
    x = str[0..j] + " " + str[(j+1)..(-1)]
    tmp << x
  }
  ary = tmp
  #p ary
end

ans = 0
ary.each{|str|
  ans += str.split(" ").map{|al| al.to_i}.inject(:+)
}
puts ans


