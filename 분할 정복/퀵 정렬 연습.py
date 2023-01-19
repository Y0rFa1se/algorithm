def quick_sort(messy_list: list) -> list:
	def cut(messy_list: list) -> tuple:
		stand = messy_list[0]
		del(messy_list[0])
		less_or_equal = []
		greater = []
		loe_len = 0

		for val in messy_list:
			if val <= stand:
				less_or_equal.append(val)
				loe_len += 1
			else:
				greater.append(val)

		return (less_or_equal, [stand], greater, loe_len)
	def _quick_sort(messy_list: list, list_len: int) -> list:
		if list_len == 0:
			return []

		less_or_equal, stand, greater, loe_len = cut(messy_list)

		less_or_equal = _quick_sort(less_or_equal, loe_len)
		greater = _quick_sort(greater, list_len - loe_len - 1)

		return less_or_equal + stand + greater

	return _quick_sort(messy_list, len(messy_list))

#test
nums = list(map(int, input().split()))
print(quick_sort(nums))