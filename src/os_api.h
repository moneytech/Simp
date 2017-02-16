

#ifndef OS_API_H
#define OS_API_H

#include <cstdlib>
#include <cassert>
#include <cstring>

#include <stdint.h>
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t   u8;

typedef int64_t  s64;
typedef int32_t  s32;
typedef int16_t  s16;
typedef int8_t    s8;

template <typename T>
struct Array {
	T *data = nullptr;
	int reserved = 0;
	int count = 0;

	void reserve(int amount) {
		if (amount <= count) assert(0);

		T *new_data = (T *)malloc(sizeof(T) * amount);
		memcpy(new_data, data, sizeof(T) * count);
		free(data);
		data = new_data;
		reserved = amount;
	}

	T &operator[] (int index) {
		assert(index >= 0 && index < count);
		return data[index];
	}

	void add(T item) {
		if ((count+1) >= reserved) reserve((count+1) * 2);
		data[count] = item;
		count++;
	}

	void remove(int index) {
		assert(index >= 0 && index < count);
		if ((count-(index+1)) > 0)
			memmove(&data[index], &data[index+1], sizeof(T) * (count-(index+1)));
		count--;
	}

	void clear() {
		 count = 0;
	}
};


#ifdef WIN32
typedef HWND OS_Window;
#else
#include <X11/X.h>
#include <GL/glx.h>
typedef Window OS_Window; // X11 Window
typedef GLXContext OS_GL_Context;
#endif


OS_Window os_create_window(s32 width, s32 height, const char *title);
OS_GL_Context os_create_gl_context(OS_Window win);
void os_close_window(OS_Window win);
void os_swap_buffers(OS_Window win);
s32  os_number_open_windows();
void os_pump_input();
void os_make_current(OS_Window win, OS_GL_Context ctx);
void os_get_window_dimensions(OS_Window win, s32 *width, s32 *height);

enum Event_Type {
	NO_EVENT,
	KEYBOARD,
	QUIT
};

struct Input_Event {
	Event_Type type;
	OS_Window window;
};

extern Array<Input_Event> input_events;

#endif