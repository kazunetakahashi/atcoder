@h, @w, @n = gets.chomp.split(" ").map{|i| i.to_i}

@hash = {}

for i in 0...@n
  a, b = gets.chomp.split(" ").map{|j| j.to_i}
  a -= 1
  b -= 1
  @hash[[a, b]] = 1
end

def valid(x, y)
  return 0 <= x && x < @h && 0 <= y && y < @w
end

@ans = Array.new(10){0}

@hash.each{|key, val|
  x = key[0]
  y = key[1]
  for i in 0...3
    for j in 0...3
      nx = x - i
      ny = y - j
      cnt = 0
      out = false
      for k in 0...3
        for l in 0...3
          sx = nx + k
          sy = ny + l
          if !valid(sx, sy)
            out = true
          elsif @hash.has_key?([sx, sy])
            cnt += 1
          end
        end
      end
      if !out
        @ans[out] += 1
      end
    end
  end
}

sum = 0
for i in 1..9
  @ans[i] /= i
  sum += @ans[i]
end

@ans[0] = (@h-2) * (@w-2) - sum;

for i in 0..9
  puts @ans[i]
end
