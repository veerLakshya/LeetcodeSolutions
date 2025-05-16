type Stack[T any] struct {
	elements []T
}
func (s *Stack[T]) push(element T) {
	s.elements = append(s.elements, element)
}
func (s *Stack[T]) pop() (T, bool) {
	n := len(s.elements)
	if n == 0 {
		var zero T
		return zero, false
	}
	res := s.elements[n-1]
	s.elements = s.elements[:n-1]
	return res, true
}
func (s *Stack[T]) isEmpty() bool {
	return len(s.elements) == 0
}
func (s *Stack[T]) top() (T, bool) {
	if len(s.elements) == 0 {
		var zero T
		return zero, false
	}
	return s.elements[len(s.elements)-1], true
}
func (s *Stack[T]) print() {
	if len(s.elements) == 0 {
		fmt.Println("stack is empty")
		return
	}
	for _, element := range s.elements {
		fmt.Println(element)
	}
}

func buildArray(target []int, n int) []string {
    st := Stack[string]{}
    for i := 1; i != target[0]; i++ {
        st.push("Push")
        st.push("Pop")
    }
    for i := 0; i < len(target); i++ {
        if i != 0 && target[i] - target[i-1] != 1 {
            for y := target[i] - target[i-1] - 1; y > 0; y-- {
                st.push("Push")
            }
            for y := target[i] - target[i-1] - 1; y > 0; y-- {
                st.push("Pop")
            }
        }
        st.push("Push")
    }
    return st.elements
}