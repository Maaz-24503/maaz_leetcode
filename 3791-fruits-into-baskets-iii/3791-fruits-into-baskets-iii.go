type SegTree struct {
	n   int
	seg []int
}

func (s *SegTree) update(p int) {
	s.seg[p] = max(s.seg[p<<1], s.seg[p<<1|1])
}

func (s *SegTree) build(p, l, r int, baskets []int) {
	if l == r {
		s.seg[p] = baskets[l]
		return
	}
	mid := (l + r) >> 1
	s.build(p<<1, l, mid, baskets)
	s.build(p<<1|1, mid+1, r, baskets)
	s.update(p)
}

func (s *SegTree) assign(x, val, p, l, r int) {
	if x < l || x > r {
		return
	}
	if l == r {
		s.seg[p] = val
		return
	}
	mid := (l + r) >> 1
	s.assign(x, val, p<<1, l, mid)
	s.assign(x, val, p<<1|1, mid+1, r)
	s.update(p)
}

func (s *SegTree) firstLarger(val, p, l, r int) int {
	if s.seg[p] < val {
		return r + 1
	}
	if l == r {
		return r
	}
	mid := (l + r) >> 1
	lf := s.firstLarger(val, p<<1, l, mid)
	if lf <= mid {
		return lf
	}
	return s.firstLarger(val, p<<1|1, mid+1, r)
}

func numOfUnplacedFruits(fruits []int, baskets []int) int {
	n := len(baskets)
	s := &SegTree{
		n:   n,
		seg: make([]int, 4*n),
	}
	s.build(1, 0, n-1, baskets)

	ans := 0
	for _, fruit := range fruits {
		pos := s.firstLarger(fruit, 1, 0, n-1)
		if pos == n {
			ans++
		} else {
			s.assign(pos, 0, 1, 0, n-1)
		}
	}
	return ans
}