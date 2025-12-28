import (
    "container/heap"
    "sort"
)

type RoomHeap []int // Min-heap for free rooms

func (h RoomHeap) Len() int            { return len(h) }
func (h RoomHeap) Less(i, j int) bool  { return h[i] < h[j] }
func (h RoomHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *RoomHeap) Push(x interface{}) { *h = append(*h, x.(int)) }
func (h *RoomHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[:n-1]
    return x
}

type BusyRoom struct {
    endTime int
    roomNum int
}

type BusyHeap []BusyRoom // Min-heap of rooms in use based on endTime

func (h BusyHeap) Len() int            { return len(h) }
func (h BusyHeap) Less(i, j int) bool {
    if h[i].endTime == h[j].endTime {
        return h[i].roomNum < h[j].roomNum
    }
    return h[i].endTime < h[j].endTime
}
func (h BusyHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *BusyHeap) Push(x interface{}) { *h = append(*h, x.(BusyRoom)) }
func (h *BusyHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[:n-1]
    return x
}

func mostBooked(n int, meetings [][]int) int {
    sort.Slice(meetings, func(i, j int) bool {
        return meetings[i][0] < meetings[j][0]
    })

    freeRooms := &RoomHeap{}
    for i := 0; i < n; i++ {
        heap.Push(freeRooms, i)
    }

    roomUseCount := make([]int, n)
    roomFree := &BusyHeap{}

    for _, meeting := range meetings {
        start, end := meeting[0], meeting[1]

        // Free up rooms where meetings have already ended
        for roomFree.Len() > 0 && (*roomFree)[0].endTime <= start {
            heap.Push(freeRooms, heap.Pop(roomFree).(BusyRoom).roomNum)
        }

        if freeRooms.Len() > 0 {
            room := heap.Pop(freeRooms).(int)
            heap.Push(roomFree, BusyRoom{end, room})
            roomUseCount[room]++
        } else {
            next := heap.Pop(roomFree).(BusyRoom)
            // Delay this meeting to when the room becomes available
            newEnd := next.endTime + (end - start)
            heap.Push(roomFree, BusyRoom{newEnd, next.roomNum})
            roomUseCount[next.roomNum]++
        }
    }

    maxUsed := 0
    result := 0
    for i := 0; i < n; i++ {
        if roomUseCount[i] > maxUsed {
            maxUsed = roomUseCount[i]
            result = i
        }
    }

    return result
}