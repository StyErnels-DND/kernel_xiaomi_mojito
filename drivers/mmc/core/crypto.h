/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright 2020 Google LLC
 * Copyright (C) 2021 XiaoMi, Inc.
 */

#ifndef _MMC_CORE_CRYPTO_H
#define _MMC_CORE_CRYPTO_H

struct mmc_host;
struct mmc_queue_req;
struct request;
struct request_queue;

#ifdef CONFIG_MMC_CRYPTO

void mmc_crypto_setup_queue(struct mmc_host *host, struct request_queue *q);

void mmc_crypto_free_host(struct mmc_host *host);

void mmc_crypto_prepare_req(struct mmc_queue_req *mqrq);

#else /* CONFIG_MMC_CRYPTO */

static inline void mmc_crypto_setup_queue(struct mmc_host *host,
					  struct request_queue *q) { }

static inline void mmc_crypto_free_host(struct mmc_host *host) { }

static inline void mmc_crypto_prepare_req(struct mmc_queue_req *mqrq) { }

#endif /* CONFIG_MMC_CRYPTO */

#endif /* _MMC_CORE_CRYPTO_H */
