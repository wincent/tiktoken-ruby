use rustc_hash::FxHashMap as HashMap;

pub fn special_tokens() -> HashMap<String, usize> {
    let mut map: HashMap<String, usize> = HashMap::default();

    // Keys and values taken from:
    // https://github.com/openai/tiktoken/blob/f19feecd071e22e02bf567ed12ccf161ce6db661/tiktoken_ext/openai_public.py#L63
    map.insert(String::from("<|endoftext|>"), 100257);
    map.insert(String::from("<|fim_prefix|>"), 100258);
    map.insert(String::from("<|fim_middle|>"), 100259);
    map.insert(String::from("<|fim_suffix|>"), 100260);
    map.insert(String::from("<|endofprompt|>"), 100276);
    map
}
