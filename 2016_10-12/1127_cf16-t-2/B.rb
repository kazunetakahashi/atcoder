class Array
  def >=(other)
    for i in 0...other.size()
      if self[i] > other[i]
        return true
      elsif self[i] < other[i]
        return false
      end
    end
    return true
  end
end

def magic(ary)
  ans = []
  now = 0
  ary.each{|x|
    now += x
    ans << now
  }
  return ans
end

n, m = gets.chomp.split(" ").map{|x| x.to_i}
a = []
n.times{
  a << gets.chomp.split(" ").map{|x| x.to_i}
}
ans = 0
for i in 1...n
  if (a[i-1][0] > a[i][0])
    puts "-1"
    exit
  end
end

for i in 1...n
  while (a[i-1] >= a[i])
    a[i] = magic(a[i])
    ans += 1
  end
end
puts ans

