/*
 * Copyright (c) 2018-2022 Jean-Philippe Bruyère <jp_bruyere@hotmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
 * Software, and to permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <vkh/vkh_queue.h>
#include <vkh/vkh_device.h>
#include <vkh/vkh_phyinfo.h>

VkhQueue _init_queue (VkhDevice dev) {
	VkhQueue q	= (vkh_queue_t*)calloc(1, sizeof(vkh_queue_t));
	q->dev = dev;
	return q;
}


VkhQueue vkh_queue_create (VkhDevice vkh, uint32_t familyIndex, uint32_t qIndex) {
	VkhQueue q	= _init_queue (dev);
	q->familyIndex	= familyIndex;
	vkGetDeviceQueue (vkh->device, familyIndex, qIndex, &q->queue);
	return q;
}

//VkhQueue vkh_queue_find (VkhDevice dev, VkQueueFlags flags) {

//	  return q;
//}

void vkh_queue_destroy (VkhQueue queue){
	free (queue);
}
